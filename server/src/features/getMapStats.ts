import { and, count, eq, sql, sum } from 'drizzle-orm';
import { db } from '../db/index';
import { map, match, matchPlayed } from '../db/schema';

interface MapStatsRequest {
  playerId: string;
  //mapId: string;
}

export async function getMapStats({ playerId /*, mapId*/ }: MapStatsRequest) {
  const mapStats = await db
    .select({
      mapId: map.mapId,
      mapName: map.name,
      totalMatches: count(matchPlayed.matchId).as('totalMatches'),
      totalVictories:
        sql`SUM (CASE WHEN ${match.result} = TRUE THEN 1 ELSE 0 END)`
          .mapWith(Number)
          .as('totalVictories'),
      totalKills: sum(matchPlayed.kills).mapWith(Number).as('totalKills'),
      totalDeaths: sum(matchPlayed.deaths).mapWith(Number).as('totalDeaths'),
      totalMultikills: sum(matchPlayed.multiKills)
        .mapWith(Number)
        .as('totalMultikills'),
      totalMvps: sum(matchPlayed.mvps).mapWith(Number).as('totalMVPs'),
    })
    .from(matchPlayed)
    .innerJoin(match, eq(matchPlayed.matchId, match.matchId))
    .innerJoin(map, eq(match.mapId, map.mapId))
    // alteração
    .where(eq(matchPlayed.playerId, playerId))
    .groupBy(map.mapId, map.name);

  return mapStats;
}
