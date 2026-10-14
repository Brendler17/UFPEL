import { useEffect, useState } from 'react';

interface MapStatsResponse {
  mapId: string;
  mapName: string;
  totalMatches: number;
  totalVictories: number;
  totalKills: number;
  totalDeaths: number;
  totalMultikills: number;
  totalMvps: number;
}

interface MapStatsProps {
  playerId: string;
}

export default function Maps({ playerId }: MapStatsProps) {
  const [mapStats, setMapStats] = useState<MapStatsResponse[]>([]);

  useEffect(() => {
    fetch(`http://localhost:3333/map-stats?playerId=${playerId}`)
      .then(response => {
        return response.json();
      })
      .then(data => {
        setMapStats(data);
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
                Mapa
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Partidas
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Vitórias
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Derrotas
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                % Vitórias
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Kills
              </th>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Mortes
              </th>
              <th className="w-2/12 px-8 py-3 text-left ">MVP's</th>
            </tr>
          </thead>
          <tbody>
            {mapStats.map(item => (
              <tr key={item.mapId}>
                <td className="px-8 py-4 border-r border-zinc-500">
                  {item.mapName}
                </td>
                <td className="px-8 py-4 border-r border-zinc-500">
                  {item.totalMatches}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.totalVictories}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.totalMatches - item.totalVictories}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {(item.totalVictories / item.totalMatches) * 100}%
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.totalKills}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.totalDeaths}
                </td>
                <td className="px-8 py-4">{item.totalMvps}</td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </>
  );
}
