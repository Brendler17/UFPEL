import { useEffect, useState } from 'react';

interface PlayerHistoryResponse {
  matchId: string;
  result: boolean;
  mapName: string;
  kills: number;
  deaths: number;
  assists: number;
}

interface MatchesProps {
  playerId: string;
  onMatchClick: (matchId: string) => void;
}

export default function Matches({ playerId, onMatchClick }: MatchesProps) {
  const [playerHistory, setPlayerHistory] = useState<PlayerHistoryResponse[]>(
    []
  );

  useEffect(() => {
    fetch(`http://localhost:3333/player-history?playerId=${playerId}`)
      .then(response => {
        return response.json();
      })
      .then(data => {
        setPlayerHistory(data);
      });
  }, [playerId]);

  return (
    <>
      <h1 className="text-4xl font-bold">Histórico de Partidas</h1>

      <div className="bg-zinc-900 p-4 rounded-lg">
        <table className="table-fixed w-full border-collapse">
          <thead className="bg-zinc-900 border-b  border-zinc-500">
            <tr>
              <th className="w-2/12 px-8 py-3 text-left border-r border-zinc-500">
                Mapa
              </th>
              <th className="w-4/12 px-8 py-3 text-left  border-r border-zinc-500">
                Resultado
              </th>
              <th className="w-4/12 px-8 py-3 text-left border-r border-zinc-500">
                Kills
              </th>
              <th className="w-3/12 px-8 py-3 text-left">Mortes</th>
            </tr>
          </thead>
          <tbody>
            {playerHistory.map(item => (
              <tr
                key={item.matchId}
                className="hover:bg-orange-800 transition-colors cursor-pointer"
                onClick={() => onMatchClick(item.matchId)}
              >
                <td className="px-8 py-4 border-r border-zinc-500">
                  {item.mapName}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500">
                  {item.result ? 'Vitória' : 'Derrota'}
                </td>
                <td className="px-8 py-4 border-r  border-zinc-500 text-orange-400">
                  {item.kills}
                </td>
                <td className="px-8 py-4">{item.deaths}</td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
    </>
  );
}
