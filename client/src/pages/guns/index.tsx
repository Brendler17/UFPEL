import { useEffect, useState } from 'react';

interface GunStatsResponse {
  killsWithGunPercentage: number;
  headshotPercentage: number;
  gunId: string;
  gunName: string;
  totalKills: number;
  totalHeadshots: number;
}

interface GunStatsProps {
  playerId: string;
}

export default function Matches({ playerId }: GunStatsProps) {
  const [gunStats, setGunStats] = useState<GunStatsResponse[]>([]);

  useEffect(() => {
    fetch(`http://localhost:3333/gun-stats?playerId=${playerId}`)
      .then(response => {
        return response.json();
      })
      .then(data => {
        setGunStats(data);
      });
  }, [playerId]);

  return (
    <>
      <h1 className="text-4xl font-bold">Estatísticas Armas</h1>

      <div className="bg-zinc-900 p-4 rounded-lg">
        <table className="table-fixed border-collapse">
          <thead className="bg-zinc-900 border-b  border-zinc-500">
            <tr>
              <th className="w-2xs px-8 py-3 text-left border-r border-zinc-500">
                Arma
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Kills
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Headshots
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                % Kills
              </th>
              <th className="w-2/12 px-8 py-3 text-left ">% HS</th>
            </tr>
          </thead>
          <tbody>
            {gunStats.map(item => (
              <tr
                key={item.gunId}
                className="hover:bg-orange-800 transition-colors"
              >
                <td className="px-8 py-4 border-r border-zinc-500">
                  {item.gunName}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.totalKills}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.totalHeadshots}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.killsWithGunPercentage.toFixed(2)} %
                </td>
                <td className="px-8 py-4">
                  {item.headshotPercentage.toFixed(2)} %
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </>
  );
}
