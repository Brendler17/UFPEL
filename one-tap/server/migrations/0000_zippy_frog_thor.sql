CREATE TABLE "frags" (
	"frag_id" text PRIMARY KEY NOT NULL,
	"match_played_id" text NOT NULL,
	"gun_id" text NOT NULL,
	"number_of_frags" integer NOT NULL,
	"headshots" integer NOT NULL,
	CONSTRAINT "frags_match_played_id_gun_id_unique" UNIQUE("match_played_id","gun_id")
);
--> statement-breakpoint
CREATE TABLE "gun" (
	"gun_id" text PRIMARY KEY NOT NULL,
	"name" text NOT NULL,
	"type" text NOT NULL
);
--> statement-breakpoint
CREATE TABLE "map" (
	"map_id" text PRIMARY KEY NOT NULL,
	"name" text NOT NULL,
	"category" text NOT NULL,
	"in_rotation" boolean DEFAULT false NOT NULL
);
--> statement-breakpoint
CREATE TABLE "match" (
	"match_id" text PRIMARY KEY NOT NULL,
	"map_id" text NOT NULL,
	"result" boolean NOT NULL,
	"mode" text NOT NULL,
	"created_at" timestamp with time zone DEFAULT now() NOT NULL
);
--> statement-breakpoint
CREATE TABLE "match_played" (
	"match_played_id" text PRIMARY KEY NOT NULL,
	"player_id" text NOT NULL,
	"match_id" text NOT NULL,
	"kills" integer NOT NULL,
	"assists" integer NOT NULL,
	"deaths" integer NOT NULL,
	"mvps" integer NOT NULL,
	"flash_assists" integer NOT NULL,
	"first_kills" integer NOT NULL,
	"multi_kills" integer NOT NULL,
	"headshots" integer NOT NULL,
	"rounds_played" integer NOT NULL,
	"time_played" integer NOT NULL,
	"damage" integer NOT NULL,
	CONSTRAINT "match_played_player_id_match_id_unique" UNIQUE("player_id","match_id"),
	CONSTRAINT "rounds_played_check" CHECK ("match_played"."rounds_played" BETWEEN 24 AND 30)
);
--> statement-breakpoint
CREATE TABLE "player" (
	"steam_id" text PRIMARY KEY NOT NULL,
	"nickname" text NOT NULL,
	"email" text NOT NULL,
	"password" text NOT NULL,
	"created_at" timestamp with time zone DEFAULT now() NOT NULL,
	CONSTRAINT "player_email_unique" UNIQUE("email")
);
--> statement-breakpoint
CREATE TABLE "subscription" (
	"subscription_id" text PRIMARY KEY NOT NULL,
	"player_id" text NOT NULL,
	"type" text NOT NULL,
	"start_date" timestamp with time zone NOT NULL,
	"end_date" timestamp with time zone NOT NULL
);
--> statement-breakpoint
ALTER TABLE "frags" ADD CONSTRAINT "frags_match_played_id_match_played_match_played_id_fk" FOREIGN KEY ("match_played_id") REFERENCES "public"."match_played"("match_played_id") ON DELETE no action ON UPDATE no action;--> statement-breakpoint
ALTER TABLE "frags" ADD CONSTRAINT "frags_gun_id_gun_gun_id_fk" FOREIGN KEY ("gun_id") REFERENCES "public"."gun"("gun_id") ON DELETE no action ON UPDATE no action;--> statement-breakpoint
ALTER TABLE "match" ADD CONSTRAINT "match_map_id_map_map_id_fk" FOREIGN KEY ("map_id") REFERENCES "public"."map"("map_id") ON DELETE no action ON UPDATE no action;--> statement-breakpoint
ALTER TABLE "match_played" ADD CONSTRAINT "match_played_player_id_player_steam_id_fk" FOREIGN KEY ("player_id") REFERENCES "public"."player"("steam_id") ON DELETE no action ON UPDATE no action;--> statement-breakpoint
ALTER TABLE "match_played" ADD CONSTRAINT "match_played_match_id_match_match_id_fk" FOREIGN KEY ("match_id") REFERENCES "public"."match"("match_id") ON DELETE no action ON UPDATE no action;--> statement-breakpoint
ALTER TABLE "subscription" ADD CONSTRAINT "subscription_player_id_player_steam_id_fk" FOREIGN KEY ("player_id") REFERENCES "public"."player"("steam_id") ON DELETE no action ON UPDATE no action;