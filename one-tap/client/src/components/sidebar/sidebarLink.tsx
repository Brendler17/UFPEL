import type { ReactNode, MouseEventHandler } from 'react';

interface SidebarLinkProps {
  children: ReactNode;
  onClick?: MouseEventHandler<HTMLDivElement>;
}

export default function SidebarLink({ children, onClick }: SidebarLinkProps) {
  return (
    <div
      onClick={onClick}
      className="flex items-center gap-3 rounded-lg px-3 py-2 hover:bg-orange-800 cursor-pointer"
    >
      {children}
    </div>
  );
}
