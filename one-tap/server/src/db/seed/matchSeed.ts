import { db } from '../index';
import { match } from '../schema';

export async function matchSeed(mapResponseIds: string[]) {
  const matchResponse = await db
    .insert(match)
    .values([
      {
        mapId: mapResponseIds[0],
        result: true,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponseIds[1],
        result: false,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponseIds[4],
        result: false,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponseIds[0],
        result: true,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponseIds[1],
        result: true,
        mode: 'special',
        createdAt: new Date(),
      },
    ])
    .returning();

  const matchResponseIds = matchResponse.map(m => m.matchId);

  return {
    matchResponseIds,
  };
}
