import { z } from 'zod';
import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getPlayerSubscription } from '../../features/getPlayerSubscription';

export const getPlayerSubscriptionRoute: FastifyPluginAsyncZod = async app => {
  app.get(
    '/player-subscription',
    {
      schema: {
        querystring: z.object({
          playerId: z.string(),
        }),
      },
    },
    async (request, reply) => {
      try {
        const { playerId } = request.query;

        if (!playerId) {
          return reply.code(400).send({ error: 'playerId is required' });
        }

        const playerSubscription = await getPlayerSubscription({ playerId });

        return reply.code(200).send(playerSubscription);
      } catch (error) {
        console.log(error);
        return reply.code(500).send({ error: 'internal server error' });
      }
    }
  );
};
