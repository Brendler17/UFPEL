import { and, eq } from 'drizzle-orm';
import { db } from '../db/index';
import { matchPlayed } from '../db/schema';

interface MatchStatsRequest {
  playerId: string;
  matchId: string;
}

export async function getMatchStats({ playerId, matchId }: MatchStatsRequest) {
  const matchStats = await db
    .select()
    .from(matchPlayed)
    .where(
      and(eq(matchPlayed.playerId, playerId), eq(matchPlayed.matchId, matchId))
    );

  const derivedStats = {
    diff: matchStats[0].kills - matchStats[0].deaths,
    adr: matchStats[0].damage / matchStats[0].roundsPlayed,
    kdr: matchStats[0].kills / matchStats[0].deaths || 0,
    headshotPercentage: matchStats[0].headshots
      ? (matchStats[0].headshots / matchStats[0].kills) * 100
      : 0,
  };

  return {
    ...matchStats[0],
    ...derivedStats,
  };
}
