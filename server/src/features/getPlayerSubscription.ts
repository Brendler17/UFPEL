import { eq } from 'drizzle-orm';
import { db } from '../db/index';
import { subscription } from '../db/schema';

interface PlayerSubscriptionRequest {
  playerId: string;
}

export async function getPlayerSubscription({
  playerId,
}: PlayerSubscriptionRequest) {
  const playerSubscription = await db
    .select()
    .from(subscription)
    .where(eq(subscription.playerId, playerId));

  return {
    ...playerSubscription[0],
  };
}
