import { db } from '../index';
import { matchPlayed } from '../schema';

export async function matchPlayedSeed(
  matchResponseIds: string[],
  playerResponse: { steamId: string }
) {
  const allMatchPlayed = [];
  for (let counter = 0; counter < matchResponseIds.length; counter++) {
    const numberOfKills = Math.floor(Math.random() * 50);
    const numberOfHeadshots = Math.floor(Math.random() * numberOfKills);
    const matchPlayedResponse = await db
      .insert(matchPlayed)
      .values([
        {
          playerId: playerResponse.steamId,
          matchId: matchResponseIds[counter],
          kills: numberOfKills,
          deaths: Math.floor(Math.random() * 24),
          assists: Math.floor(Math.random() * 20),
          mvps: Math.floor(Math.random() * 10),
          flashAssists: Math.floor(Math.random() * 15),
          firstKills: Math.floor(Math.random() * 5),
          multiKills: Math.floor(Math.random() * 5),
          headshots: numberOfHeadshots,
          roundsPlayed: Math.floor(Math.random() * (30 - 24 + 1)) + 24,
          timePlayed: Math.floor(Math.random() * 3600) + 600,
          damage: Math.floor(Math.random() * 5000),
        },
      ])
      .returning();

    allMatchPlayed.push(matchPlayedResponse[0]);
  }

  const matchPlayedInfo = allMatchPlayed.map(m => {
    return {
      id: m.matchPlayedId,
      kills: m.kills,
      headshots: m.headshots,
    };
  });

  return {
    matchPlayedInfo,
  };
}
