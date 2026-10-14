import { useEffect, useState } from 'react';

interface MatchStatsResponse {
  matchPlayedId: string;
  playerId: string;
  matchId: string;
  kills: number;
  assists: number;
  deaths: number;
  mvps: number;
  flashAssists: number;
  firstKills: number;
  multiKills: number;
  headshots: number;
  roundsPlayed: number;
  timePlayed: number;
  damage: number;
  diff: number;
  adr: number;
  kdr: number;
  headshotPercentage: number;
}

interface MatchProps {
  playerId: string;
  matchId: string;
}

export default function Match({ playerId, matchId }: MatchProps) {
  const [matchStats, setMatchStats] = useState<MatchStatsResponse>();

  useEffect(() => {
    fetch(
      `http://localhost:3333/match-stats?playerId=${playerId}&matchId=${matchId}`
    )
      .then(response => {
        return response.json();
      })
      .then(data => {
        setMatchStats(data);
      });
  }, [playerId, matchId]);

  console.log('match', matchId);

  return (
    <>
      <h1 className="text-4xl font-bold">Partida</h1>

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
              <td className="px-8 py-4 border-r border-zinc-500">Kills</td>
              <td className="px-8 py-4">{matchStats?.kills}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Assistências
              </td>
              <td className="px-8 py-4">{matchStats?.assists}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Mortes</td>
              <td className="px-8 py-4">{matchStats?.deaths}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Diff</td>
              <td className="px-8 py-4">{matchStats?.diff}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Headshots</td>
              <td className="px-8 py-4">{matchStats?.headshots}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Headshots %
              </td>
              <td className="px-8 py-4">
                {matchStats?.headshotPercentage.toFixed(2)}
              </td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">ADR</td>
              <td className="px-8 py-4">{matchStats?.adr.toFixed(2)}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">KDR</td>
              <td className="px-8 py-4">{matchStats?.kdr.toFixed(2)}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">MVP's</td>
              <td className="px-8 py-4">{matchStats?.mvps}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Flash Assist
              </td>
              <td className="px-8 py-4">{matchStats?.flashAssists}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                Multi Kills
              </td>
              <td className="px-8 py-4">{matchStats?.multiKills}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">
                First Kills
              </td>
              <td className="px-8 py-4">{matchStats?.firstKills}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Rounds</td>
              <td className="px-8 py-4">{matchStats?.roundsPlayed}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Tempo</td>
              <td className="px-8 py-4">{matchStats?.timePlayed}</td>
            </tr>
            <tr>
              <td className="px-8 py-4 border-r border-zinc-500">Dano</td>
              <td className="px-8 py-4">{matchStats?.damage}</td>
            </tr>
          </tbody>
        </table>
      </div>
    </>
  );
}
