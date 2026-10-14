import { count, desc, eq, sum } from 'drizzle-orm';
import { db } from '../db/index';
import { matchPlayed, player } from '../db/schema';

export async function getPlayersRank() {
  const playersRankResponse = await db
    .select({
      playerId: player.steamId,
      playerName: player.nickName,
      totalKills: sum(matchPlayed.kills).mapWith(Number).as('totalKills'),
      totalMatches: count(matchPlayed.matchId)
        .mapWith(Number)
        .as('totalMatches'),
    })
    .from(player)
    .innerJoin(matchPlayed, eq(player.steamId, matchPlayed.playerId))
    .groupBy(player.steamId, player.nickName)
    .orderBy(desc(sum(matchPlayed.kills)));

  const rankedPlayers = playersRankResponse.map((player, index) => ({
    ...player,
    rank: index + 1,
  }));

  return rankedPlayers;
}
