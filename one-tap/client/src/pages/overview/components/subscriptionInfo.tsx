import { useEffect, useState } from 'react';

interface SubscriptionInfoResponse {
  subscriptionId: string;
  playerId: string;
  playerName: string;
  type: string;
  startDate: Date;
  endDate: Date;
}

interface SubscriptionInfoProps {
  playerId: string;
}

export default function SubscriptionInfo({ playerId }: SubscriptionInfoProps) {
  const [subscriptionInfo, setSubscriptionInfo] =
    useState<SubscriptionInfoResponse>();

  useEffect(() => {
    fetch(`http://localhost:3333/player-subscription?playerId=${playerId}`)
      .then(response => {
        return response.json();
      })
      .then(data => {
        setSubscriptionInfo(data);
      });
  }, [playerId]);

  return (
    <div className="flex flex-col gap-2">
      <p>
        Expira em{' '}
        {subscriptionInfo?.endDate
          ? new Date(subscriptionInfo.endDate).toLocaleDateString()
          : ''}
      </p>
      <p className="font-bold">{subscriptionInfo?.playerName}</p>
      <p>Assinatura {subscriptionInfo?.type}</p>
    </div>
  );
}
