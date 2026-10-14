import { CircleUserRound } from 'lucide-react';
import { useEffect, useState } from 'react';

interface UserInfoResponse {
  playerName: string;
  type: string;
}

interface UserInfoProps {
  playerId: string;
}

export default function UserInfo({ playerId }: UserInfoProps) {
  const [userInfo, setUserInfo] = useState<UserInfoResponse>();

  useEffect(() => {
    fetch(`http://localhost:3333/player-subscription?playerId=${playerId}`)
      .then(response => {
        return response.json();
      })
      .then(data => {
        setUserInfo(data);
      });
  }, [playerId]);

  function capitalizeFirstLetter(str: string) {
    if (!str) return '';
    return str.charAt(0).toUpperCase() + str.slice(1);
  }

  return (
    <div className="flex gap-4 items-center">
      <CircleUserRound className="w-10 h-10" />
      <div className="flex-col items-center justify-center gap-3">
        <p>{userInfo?.playerName}</p>
        <p>{capitalizeFirstLetter(userInfo?.type ?? '')}</p>
      </div>
    </div>
  );
}
