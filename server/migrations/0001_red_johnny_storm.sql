ALTER TABLE "frags" DROP CONSTRAINT "frags_match_played_id_gun_id_pk";--> statement-breakpoint
ALTER TABLE "frags" ADD COLUMN "frag_id" text PRIMARY KEY NOT NULL;--> statement-breakpoint
ALTER TABLE "frags" ADD CONSTRAINT "frags_match_played_id_gun_id_unique" UNIQUE("match_played_id","gun_id");