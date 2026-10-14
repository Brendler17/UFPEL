import { db } from '../index';
import { frags } from '../schema';

export async function fragsSeed(
  matchPlayedInfo: { id: string; kills: number; headshots: number }[],
  gunResponseIds: string[]
) {
  for (let counter = 0; counter < matchPlayedInfo.length; counter++) {
    await db.insert(frags).values([
      {
        matchPlayedId: matchPlayedInfo[counter].id,
        gunId: gunResponseIds[0],
        numberOfFrags: Math.floor(matchPlayedInfo[counter].kills / 2),
        headshots: Math.floor(matchPlayedInfo[counter].headshots / 2),
      },
      {
        matchPlayedId: matchPlayedInfo[counter].id,
        gunId: gunResponseIds[1],
        numberOfFrags: Math.floor(matchPlayedInfo[counter].kills / 2),
        headshots: Math.floor(matchPlayedInfo[counter].headshots / 2),
      },
    ]);
  }
}
