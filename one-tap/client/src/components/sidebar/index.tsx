import { User, ChartLine, List, Swords, Map } from 'lucide-react';
import UserInfo from './userInfo';
import SidebarLink from './sidebarLink';

interface SidebarProps {
  playerId: string;
  onSelect: (path: string) => void;
}

export default function Sidebar({ playerId, onSelect }: SidebarProps) {
  return (
    <section className="w-32 flex-1  p-16">
      <div className="flex flex-col gap-8">
        <UserInfo playerId={playerId} />
        <div className="flex flex-col gap-2">
          <SidebarLink onClick={() => onSelect('/')}>
            <User />
            Visão Geral
          </SidebarLink>
          <SidebarLink onClick={() => onSelect('/matches')}>
            <List />
            Partidas
          </SidebarLink>
          <SidebarLink onClick={() => onSelect('/stats')}>
            <ChartLine />
            Estatísticas
          </SidebarLink>
          <SidebarLink onClick={() => onSelect('/guns')}>
            <Swords />
            Armas
          </SidebarLink>
          <SidebarLink onClick={() => onSelect('/maps')}>
            <Map />
            Mapas
          </SidebarLink>
        </div>
      </div>
    </section>
  );
}
