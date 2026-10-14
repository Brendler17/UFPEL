import { db } from '../index';
import { player, subscription } from '../schema';
import dayjs from 'dayjs';

export async function playerSeed() {
  const playerResponse = await db
    .insert(player)
    .values([
      {
        nickName: 'Dekinn',
        email: 'gbrendler@hotmail.com',
        password: '123456789',
        createdAt: new Date(),
      },
    ])
    .returning();

  await db.insert(subscription).values([
    {
      playerId: playerResponse[0].steamId,
      type: 'premium',
      startDate: new Date(),
      endDate: new Date(dayjs().add(1, 'month').toDate()),
    },
  ]);

  return {
    steamId: playerResponse[0].steamId,
  };
}
