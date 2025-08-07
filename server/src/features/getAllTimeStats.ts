import { sum, eq, count } from 'drizzle-orm';
import { db } from '../db/index';
import { matchPlayed } from '../db/schema';

interface AllTimeStatsRequest {
  playerId: string;
}

export async function getAllTimeStats({ playerId }: AllTimeStatsRequest) {
  const allTimeStats = await db
    .select({
      playerId: matchPlayed.playerId,
      totalMatchPlayeds: count(matchPlayed.matchId).as('totalMatchPlayeds'),
      totalKills: sum(matchPlayed.kills).mapWith(Number).as('totalKills'),
      totalAssists: sum(matchPlayed.assists).mapWith(Number).as('totalAssists'),
      totalDeaths: sum(matchPlayed.deaths).mapWith(Number).as('totalDeaths'),
      totalMvps: sum(matchPlayed.mvps).mapWith(Number).as('totalMvps'),
      totalFlashAssists: sum(matchPlayed.flashAssists)
        .mapWith(Number)
        .as('totalFlashAssists'),
      totalFirstKilss: sum(matchPlayed.firstKills)
        .mapWith(Number)
        .as('totalFirstKills'),
      totalMultiKills: sum(matchPlayed.multiKills)
        .mapWith(Number)
        .as('totalMultiKills'),
      totalHeadshots: sum(matchPlayed.headshots)
        .mapWith(Number)
        .as('totalHeadshots'),
      totalRoundsPlayed: sum(matchPlayed.roundsPlayed)
        .mapWith(Number)
        .as('totalRoundsPlayed'),
      totalTimePlayed: sum(matchPlayed.timePlayed)
        .mapWith(Number)
        .as('totalTimePlayed'),
      totalDamage: sum(matchPlayed.damage).mapWith(Number).as('totalDamage'),
    })
    .from(matchPlayed)
    .where(eq(matchPlayed.playerId, playerId))
    .groupBy(matchPlayed.playerId);

  const derivedAllTimeStats = {
    diff: allTimeStats[0].totalKills - allTimeStats[0].totalDeaths,
    adr: allTimeStats[0].totalDamage / allTimeStats[0].totalRoundsPlayed,
    kdr: allTimeStats[0].totalKills / allTimeStats[0].totalDeaths || 0,
    headshotPercentage:
      allTimeStats[0].totalHeadshots / allTimeStats[0].totalKills || 0,
  };

  return {
    ...allTimeStats[0],
    ...derivedAllTimeStats,
  };
}
