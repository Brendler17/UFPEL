import { useEffect, useState } from 'react';

interface PlayerStatsResponse {
  playerId: string;
  totalMatchPlayeds: number;
  totalVictories: number;
  totalKills: number;
  totalAssists: number;
  totalDeaths: number;
  totalMvps: number;
  totalFlashAssists: number;
  totalFirstKilss: number;
  totalMultiKills: number;
  totalHeadshots: number;
  totalRoundsPlayed: number;
  totalTimePlayed: number;
  totalDamage: number;
  diff: number;
  adr: number;
  kdr: number;
  headshotPercentage: number;
}

interface PlayerStatsProps {
  playerId: string;
}

export default function Matches({ playerId }: PlayerStatsProps) {
  const [playerStats, setPlayerStats] = useState<PlayerStatsResponse>();

  useEffect(() => {
    fetch(`http://localhost:3333/all-time-stats?playerId=${playerId}`)
      .then(response => {
        return response.json();
      })
      .then(data => {
        setPlayerStats(data);
      });
  }, [playerId]);

  return (
    <>
      <h1 className="text-4xl font-bold">Estatísticas Totais</h1>

      <div className="bg-zinc-900 p-4 rounded-lg">
        <table className="table-fixed border-collapse">
          <thead className="bg-zinc-900 border-b  border-zinc-500">
            <tr>
              <th className="w-2xs px-8 py-3 text-left border-r border-zinc-500">
                Estatística
              </th>
              <th className="w-4/12 px-8 py-3 text-left">Valor</th>
            </tr>
          </thead>
          <tbody>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Partidas Jogadas
              </td>
              <td className="px-8 py-4">{playerStats?.totalMatchPlayeds}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Vitórias</td>
              <td className="px-8 py-4">{playerStats?.totalVictories}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Derrotas</td>
              <td className="px-8 py-4">
                {(playerStats?.totalMatchPlayeds ?? 0) -
                  (playerStats?.totalVictories ?? 0)}
              </td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Abates</td>
              <td className="px-8 py-4">{playerStats?.totalKills}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Assistências
              </td>
              <td className="px-8 py-4">{playerStats?.totalAssists}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Mortes</td>
              <td className="px-8 py-4">{playerStats?.totalDeaths}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Diff</td>
              <td className="px-8 py-4">{playerStats?.diff}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">ADR</td>
              <td className="px-8 py-4">{playerStats?.adr.toFixed(2)}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">KDR</td>
              <td className="px-8 py-4">{playerStats?.kdr.toFixed(2)}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Headshots</td>
              <td className="px-8 py-4">{playerStats?.totalHeadshots}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">HS %</td>
              <td className="px-8 py-4">
                {playerStats?.headshotPercentage.toFixed(2)}
              </td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">MVP's</td>
              <td className="px-8 py-4">{playerStats?.totalMvps}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                First Kills
              </td>
              <td className="px-8 py-4">{playerStats?.totalFirstKilss}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Multi Kills
              </td>
              <td className="px-8 py-4">{playerStats?.totalMultiKills}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Total Dano</td>
              <td className="px-8 py-4">{playerStats?.totalDamage}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Total Tempo
              </td>
              <td className="px-8 py-4">{playerStats?.totalTimePlayed}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Total Rounds
              </td>
              <td className="px-8 py-4">{playerStats?.totalRoundsPlayed}</td>
            </tr>
          </tbody>
        </table>
      </div>
    </>
  );
}
