import { db } from './index';

export async function setupTriggers() {
  await db.execute(`
    CREATE OR REPLACE FUNCTION validar_rounds()
    RETURNS TRIGGER AS $$
    BEGIN
      IF NEW.rounds_played < 24 OR NEW.rounds_played > 30 THEN
        RAISE EXCEPTION 'O número de rounds deve estar entre 24 e 30';
      END IF;
      RETURN NEW;
    END;
    $$ LANGUAGE plpgsql;

    DO $$
    BEGIN
      IF NOT EXISTS (
        SELECT 1 FROM pg_trigger WHERE tgname = 'trg_validar_rounds'
      ) THEN
        CREATE TRIGGER trg_validar_rounds
        BEFORE INSERT OR UPDATE ON match_played
        FOR EACH ROW
        EXECUTE FUNCTION validar_rounds();
      END IF;
    END;
    $$;
  `);

  console.log('✅ Trigger criada/atualizada com sucesso!');
}
