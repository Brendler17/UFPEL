import RankingTable from './components/rankingTable';
import StatsTable from './components/statsTable';
import SubscriptionInfo from './components/subscriptionInfo';

interface OverviewProps {
  playerId: string;
}

export default function Overview({ playerId }: OverviewProps) {
  return (
    <>
      <h1 className="text-4xl font-bold">Visão Geral</h1>
      <div className="flex flex-col gap-5">
        <h2 className="font-bold">Ranking</h2>
        <RankingTable />
      </div>
      <div className="flex flex-col gap-5 w-full ">
        <h2 className="font-bold">Estatísticas Gerais</h2>
        <StatsTable playerId={playerId} />
      </div>
      <div className="flex flex-col gap-5 w-full ">
        <h2 className="font-bold">Informações do Jogador</h2>
        <SubscriptionInfo playerId={playerId} />
      </div>
    </>
  );
}
