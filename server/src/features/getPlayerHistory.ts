import { eq } from 'drizzle-orm';
import { db } from '../db/index';
import { map, match, matchPlayed } from '../db/schema';

interface PlayerHistoryRequest {
  playerId: string;
}

export async function getPlayerHistory({ playerId }: PlayerHistoryRequest) {
  const playerHistoryResponse = await db
    .select({
      matchId: matchPlayed.matchId,
      result: match.result,
      mapName: map.name,
      kills: matchPlayed.kills,
      deaths: matchPlayed.deaths,
      assists: matchPlayed.assists,
    })
    .from(matchPlayed)
    .innerJoin(match, eq(matchPlayed.matchId, match.matchId))
    .innerJoin(map, eq(match.mapId, map.mapId))
    .where(eq(matchPlayed.playerId, playerId));

  return {
    ...playerHistoryResponse,
  };
}
