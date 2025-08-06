import { db, client } from './index';
import {
  frags,
  gun,
  map,
  match,
  matchPlayed,
  player,
  subscription,
} from './schema';
import dayjs from 'dayjs';

async function seedDatabase() {
  await db.delete(frags);
  await db.delete(matchPlayed);
  await db.delete(match);
  await db.delete(gun);
  await db.delete(map);
  await db.delete(subscription);
  await db.delete(player);

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

  const mapResponse = await db
    .insert(map)
    .values([
      { name: 'Mirage', category: 'competitive', inRotation: true },
      { name: 'Dust II', category: 'competitive', inRotation: true },
      { name: 'Inferno', category: 'competitive', inRotation: true },
      { name: 'Train', category: 'competitive', inRotation: true },
      { name: 'Nuke', category: 'competitive', inRotation: true },
      { name: 'Ancient', category: 'competitive', inRotation: true },
      { name: 'Overpass', category: 'competitive', inRotation: true },
      { name: 'Vertigo', category: 'competitive', inRotation: false },
      { name: 'Cache', category: 'competitive', inRotation: false },
      { name: 'Anubis', category: 'competitive', inRotation: false },
    ])
    .returning();

  const matchResponse = await db
    .insert(match)
    .values([
      {
        mapId: mapResponse[0].mapId,
        result: true,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponse[1].mapId,
        result: false,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponse[4].mapId,
        result: false,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponse[0].mapId,
        result: true,
        mode: 'special',
        createdAt: new Date(),
      },
      {
        mapId: mapResponse[1].mapId,
        result: true,
        mode: 'special',
        createdAt: new Date(),
      },
    ])
    .returning();

  const allMatchPlayed = [];
  for (let counter = 0; counter < matchResponse.length; counter++) {
    const numberOfKills = Math.floor(Math.random() * 50);
    const numberOfHeadshots = Math.floor(Math.random() * numberOfKills);
    const matchPlayedResponse = await db
      .insert(matchPlayed)
      .values([
        {
          playerId: playerResponse[0].steamId,
          matchId: matchResponse[counter].matchId,
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

  console.log('Match Played Data:', allMatchPlayed);

  const gunResponse = await db
    .insert(gun)
    .values([
      { name: 'AK-47', type: 'Rifle' },
      { name: 'M4A1-S', type: 'Rifle' },
      { name: 'M4A4', type: 'Rifle' },
      { name: 'AUG', type: 'Rifle' },
      { name: 'FAMAS', type: 'Rifle' },
      { name: 'Galil AR', type: 'Rifle' },
      { name: 'SG 553', type: 'Rifle' },
      { name: 'AWP', type: 'Sniper' },
      { name: 'SSG 08', type: 'Sniper' },
      { name: 'SCAR-20', type: 'Sniper' },
      { name: 'G3SG1', type: 'Sniper' },
      { name: 'MAC-10', type: 'SMG' },
      { name: 'MP9', type: 'SMG' },
      { name: 'MP7', type: 'SMG' },
      { name: 'MP5-SD', type: 'SMG' },
      { name: 'UMP-45', type: 'SMG' },
      { name: 'P90', type: 'SMG' },
      { name: 'PP-Bizon', type: 'SMG' },
      { name: 'Glock-18', type: 'Pistol' },
      { name: 'USP-S', type: 'Pistol' },
      { name: 'P2000', type: 'Pistol' },
      { name: 'P250', type: 'Pistol' },
      { name: 'Five-SeveN', type: 'Pistol' },
      { name: 'CZ75-Auto', type: 'Pistol' },
      { name: 'Dual Berettas', type: 'Pistol' },
      { name: 'Desert Eagle', type: 'Pistol' },
      { name: 'R8 Revolver', type: 'Pistol' },
      { name: 'Nova', type: 'Heavy' },
      { name: 'XM1014', type: 'Heavy' },
      { name: 'MAG-7', type: 'Heavy' },
      { name: 'Sawed-Off', type: 'Heavy' },
      { name: 'M249', type: 'Heavy' },
      { name: 'Negev', type: 'Heavy' },
      { name: 'Knife', type: 'Equipment' },
      { name: 'Zeus x27', type: 'Equipment' },
    ])
    .returning();

  for (let counter = 0; counter < allMatchPlayed.length; counter++) {
    await db.insert(frags).values([
      {
        matchPlayedId: allMatchPlayed[counter].matchPlayedId,
        gunId: gunResponse[0].gunId,
        numberOfFrags: Math.floor(allMatchPlayed[counter].kills / 2),
        headshots: Math.floor(allMatchPlayed[counter].headshots / 2),
      },
      {
        matchPlayedId: allMatchPlayed[counter].matchPlayedId,
        gunId: gunResponse[1].gunId,
        numberOfFrags: Math.floor(allMatchPlayed[counter].kills / 2),
        headshots: Math.floor(allMatchPlayed[counter].headshots / 2),
      },
    ]);
  }

  seedDatabase().finally(() => {
    client.end();
  });
}

seedDatabase();
