import { eq, sum } from 'drizzle-orm';
import { db } from '../db/index';
import { frags, gun, matchPlayed } from '../db/schema';

interface GunStatsRequest {
  playerId: string;
  //gunId: string;
}

export async function getGunStats({ playerId /*, gunId*/ }: GunStatsRequest) {
  const allTimeKills = await db
    .select({
      totalKills: sum(matchPlayed.kills).mapWith(Number).as('totalKills'),
      totalHeadshots: sum(matchPlayed.headshots)
        .mapWith(Number)
        .as('totalHeadshots'),
    })
    .from(matchPlayed)
    .where(eq(matchPlayed.playerId, playerId))
    .groupBy(matchPlayed.playerId);

  const gunStats = await db
    .select({
      gunId: frags.gunId,
      gunName: gun.name,
      totalKills: sum(frags.numberOfFrags).mapWith(Number).as('totalKills'),
      totalHeadshots: sum(frags.headshots).mapWith(Number).as('totalHeadshots'),
    })
    .from(frags)
    // alteração
    .innerJoin(matchPlayed, eq(frags.matchPlayedId, matchPlayed.matchPlayedId))
    .innerJoin(gun, eq(frags.gunId, gun.gunId))
    .where(eq(matchPlayed.playerId, playerId))
    .groupBy(frags.gunId, gun.name);

  // alteração
  const result = gunStats
    .filter(g => g.totalKills > 0)
    .map(g => ({
      ...g,
      killsWithGunPercentage: (100 * g.totalKills) / allTimeKills[0].totalKills,
      headshotPercentage:
        (100 * g.totalHeadshots) / allTimeKills[0].totalHeadshots,
    }));

  return result;
}
