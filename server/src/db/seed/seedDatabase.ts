import { db, client } from '../index';
import {
  frags,
  gun,
  map,
  match,
  matchPlayed,
  player,
  subscription,
} from '../schema';
import { fragsSeed } from './fragsSeed';
import { gunSeed } from './gunSeed';
import { mapSeed } from './mapSeed';
import { matchPlayedSeed } from './matchPlayedSeed';
import { matchSeed } from './matchSeed';
import { playerSeed } from './playerSeed';

async function seedDatabase() {
  await db.delete(frags);
  await db.delete(matchPlayed);
  await db.delete(match);
  await db.delete(gun);
  await db.delete(map);
  await db.delete(subscription);
  await db.delete(player);

  const playerResponse = await playerSeed();

  const { mapResponseIds } = await mapSeed();

  const { matchResponseIds } = await matchSeed(mapResponseIds);

  const { matchPlayedInfo } = await matchPlayedSeed(
    matchResponseIds,
    playerResponse
  );

  const { gunResponseIds } = await gunSeed();

  await fragsSeed(matchPlayedInfo, gunResponseIds);

  seedDatabase().finally(() => {
    client.end();
  });
}

seedDatabase();
