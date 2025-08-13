import { eq } from 'drizzle-orm';
import { db } from '../db/index';
import { player, subscription } from '../db/schema';

interface PlayerSubscriptionRequest {
  playerId: string;
}

export async function getPlayerSubscription({
  playerId,
}: PlayerSubscriptionRequest) {
  const playerSubscription = await db
    .select({
      subscriptionId: subscription.subscriptionId,
      playerId: subscription.playerId,
      playerName: player.nickName,
      type: subscription.type,
      startDate: subscription.startDate,
      endDate: subscription.endDate,
    })
    .from(subscription)
    .innerJoin(player, eq(subscription.playerId, player.steamId))
    .where(eq(subscription.playerId, playerId));

  return {
    ...playerSubscription[0],
  };
}
