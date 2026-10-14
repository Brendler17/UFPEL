import { db } from '../index';
import { gun } from '../schema';

export async function gunSeed() {
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

  const gunResponseIds = gunResponse.map(g => g.gunId);

  return { gunResponseIds };
}
