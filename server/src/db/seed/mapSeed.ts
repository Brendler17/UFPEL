import { db } from '../index';
import { map } from '../schema';

export async function mapSeed() {
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

  const mapResponseIds = mapResponse.map(m => m.mapId);

  return {
    mapResponseIds,
  };
}
