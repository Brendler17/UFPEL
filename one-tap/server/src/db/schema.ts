import { createId } from '@paralleldrive/cuid2';
import { sql } from 'drizzle-orm';
import {
  boolean,
  pgTable,
  text,
  timestamp,
  integer,
  unique,
  check,
} from 'drizzle-orm/pg-core';

export const player = pgTable('player', {
  steamId: text('steam_id')
    .primaryKey()
    .$defaultFn(() => createId()),
  nickName: text('nickname').notNull(),
  email: text('email').notNull().unique(),
  password: text('password').notNull(),
  createdAt: timestamp('created_at', { withTimezone: true })
    .defaultNow()
    .notNull(),
});

export const subscription = pgTable('subscription', {
  subscriptionId: text('subscription_id')
    .primaryKey()
    .$defaultFn(() => createId()),
  playerId: text('player_id')
    .notNull()
    .references(() => player.steamId),
  type: text('type').notNull(),
  startDate: timestamp('start_date', { withTimezone: true }).notNull(),
  endDate: timestamp('end_date', { withTimezone: true }).notNull(),
});

export const map = pgTable('map', {
  mapId: text('map_id')
    .primaryKey()
    .$defaultFn(() => createId()),
  name: text('name').notNull(),
  category: text('category').notNull(),
  inRotation: boolean('in_rotation').default(false).notNull(),
});

export const gun = pgTable('gun', {
  gunId: text('gun_id')
    .primaryKey()
    .$defaultFn(() => createId()),
  name: text('name').notNull(),
  type: text('type').notNull(),
});

export const match = pgTable('match', {
  matchId: text('match_id')
    .primaryKey()
    .$defaultFn(() => createId()),
  mapId: text('map_id')
    .notNull()
    .references(() => map.mapId),
  result: boolean('result').notNull(),
  mode: text('mode').notNull(),
  createdAt: timestamp('created_at', { withTimezone: true })
    .defaultNow()
    .notNull(),
});

export const matchPlayed = pgTable(
  'match_played',
  {
    matchPlayedId: text('match_played_id')
      .primaryKey()
      .$defaultFn(() => createId()),
    playerId: text('player_id')
      .notNull()
      .references(() => player.steamId),
    matchId: text('match_id')
      .notNull()
      .references(() => match.matchId),
    kills: integer('kills').notNull(),
    assists: integer('assists').notNull(),
    deaths: integer('deaths').notNull(),
    mvps: integer('mvps').notNull(),
    flashAssists: integer('flash_assists').notNull(),
    firstKills: integer('first_kills').notNull(),
    multiKills: integer('multi_kills').notNull(),
    headshots: integer('headshots').notNull(),
    roundsPlayed: integer('rounds_played').notNull(),
    timePlayed: integer('time_played').notNull(),
    damage: integer('damage').notNull(),
  },
  table => ({
    playerId_matchId_key: unique().on(table.playerId, table.matchId),
    roundsPlayed_check: check(
      'rounds_played_check',
      sql`${table.roundsPlayed} BETWEEN 24 AND 30`
    ),
  })
);

export const frags = pgTable(
  'frags',
  {
    fragId: text('frag_id')
      .primaryKey()
      .$defaultFn(() => createId()),
    matchPlayedId: text('match_played_id')
      .notNull()
      .references(() => matchPlayed.matchPlayedId),
    gunId: text('gun_id')
      .notNull()
      .references(() => gun.gunId),
    numberOfFrags: integer('number_of_frags').notNull(),
    headshots: integer('headshots').notNull(),
  },
  table => ({
    matchPlayedId_gunId_key: unique().on(table.matchPlayedId, table.gunId),
  })
);
