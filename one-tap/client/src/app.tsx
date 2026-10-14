import { useState } from 'react';
import Sidebar from './components/sidebar';
import Overview from './pages/overview';
import Matches from './pages/matches';
import Stats from './pages/stats';
import Guns from './pages/guns';
import Maps from './pages/maps';
import Match from './pages/match';

export function App() {
  const [playerId, setPlayerId] = useState('xwplm5vhw0yk845hqrglihk7'); // desktop
  //const [playerId, setPlayerId] = useState('e4oge5x7k38erjl9kcq8imvu'); // asus
  const [selectedPage, setSelectedPage] = useState('/');
  const [selectedMatchId, setSelectedMatchId] = useState<string | null>(null);

  function renderContent() {
    if (selectedPage === '/match' && selectedMatchId) {
      return <Match playerId={playerId} matchId={selectedMatchId} />;
    }
    switch (selectedPage) {
      case '/':
        return <Overview playerId={playerId} />;
      case '/matches':
        return (
          <Matches
            playerId={playerId}
            onMatchClick={id => {
              setSelectedMatchId(id);
              setSelectedPage('/match');
            }}
          />
        );
      case '/stats':
        return <Stats playerId={playerId} />;
      case '/guns':
        return <Guns playerId={playerId} />;
      case '/maps':
        return <Maps playerId={playerId} />;
    }
  }
  return (
    <div className="flex flex-row justify-center gap-8 bg-zinc-950">
      <Sidebar playerId={playerId} onSelect={setSelectedPage} />
      <main className="flex-1/2 flex flex-col items-start p-16 gap-8">
        {renderContent()}
      </main>
    </div>
  );
}
