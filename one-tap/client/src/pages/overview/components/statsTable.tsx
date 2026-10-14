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

interface StatsTableProps {
  playerId: string;
}

export default function StatsTable({ playerId }: StatsTableProps) {
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

  const totalLost =
    (playerStats?.totalMatchPlayeds ?? 0) - (playerStats?.totalVictories ?? 0);

  return (
    <div className="flex gap-2 justify-between">
      <div className="bg-zinc-900 p-6 rounded-lg">
        <p className="text-base mb-1">Kills</p>
        <p className="text-2xl">{playerStats?.totalKills}</p>
      </div>
      <div className="bg-zinc-900 p-6 rounded-lg">
        <p className="text-base mb-1">Mortes</p>
        <p className="text-2xl">{playerStats?.totalDeaths}</p>
      </div>
      <div className="bg-zinc-900 p-6 rounded-lg">
        <p className="text-base mb-1">Vitórias</p>
        <p className="text-2xl">{playerStats?.totalVictories}</p>
      </div>
      <div className="bg-zinc-900 p-6 rounded-lg">
        <p className="text-base mb-1">Derrotas</p>
        <p className="text-2xl">{totalLost}</p>
      </div>
      <div className="bg-zinc-900 p-6 rounded-lg">
        <p className="text-base mb-1">Headshot %</p>
        <p className="text-2xl">{playerStats?.headshotPercentage.toFixed(2)}</p>
      </div>
    </div>
  );
}
