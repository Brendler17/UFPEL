import { z } from 'zod';
import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getPlayerHistory } from '../../features/getPlayerHistory';

export const getPlayerHistoryRoute: FastifyPluginAsyncZod = async app => {
  app.get(
    '/player-history',
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
          return reply.status(400).send({
            error: 'playerId is required',
          });
        }

        const history = await getPlayerHistory({ playerId });

        return reply.status(200).send(history);
      } catch (error) {
        console.error(error);
        return reply.status(500).send({ error: 'internal server error' });
      }
    }
  );
};
