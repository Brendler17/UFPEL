import { useEffect, useState } from 'react';

interface RankingTableResponse {
  rank: number;
  playerId: string;
  playerName: string;
  totalKills: number;
  totalMatches: number;
}

export default function RankingTable() {
  const [rankingTable, setRankingTable] = useState<RankingTableResponse[]>([]);

  useEffect(() => {
    fetch('http://localhost:3333/players-rank')
      .then(response => {
        return response.json();
      })
      .then(data => {
        setRankingTable(data);
      });
  }, []);

  return (
    <div className="bg-zinc-900 p-4 rounded-lg">
      <table className="table-fixed w-full border-collapse">
        <thead className="bg-zinc-900 border-b  border-zinc-500">
          <tr>
            <th className="w-1/12 px-8 py-3 text-center border-r border-zinc-500">
              #
            </th>
            <th className="w-4/12 px-8 py-3 text-left  border-r border-zinc-500">
              Jogador
            </th>
            <th className="w-4/12 px-8 py-3 text-left border-r border-zinc-500">
              Kills
            </th>
            <th className="w-3/12 px-8 py-3 text-left">Partidas</th>
          </tr>
        </thead>
        <tbody>
          {rankingTable.map(item => (
            <tr
              key={item.playerId}
              className="hover:bg-orange-800 transition-colors"
            >
              <td className="px-8 py-4 border-r border-zinc-500">
                {item.rank}
              </td>
              <td className="px-8 py-4 border-r  border-zinc-500">
                {item.playerName}
              </td>
              <td className="px-8 py-4 border-r  border-zinc-500 text-orange-400">
                {item.totalKills}
              </td>
              <td className="px-8 py-4">{item.totalMatches}</td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
