import { z } from 'zod';
import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getMatchStats } from '../../features/getMatchStats';

export const getMatchStatsRoute: FastifyPluginAsyncZod = async app => {
  app.get(
    '/match-stats',
    {
      schema: {
        querystring: z.object({
          playerId: z.string(),
          matchId: z.string(),
        }),
      },
    },
    async (request, reply) => {
      try {
        const { playerId, matchId } = request.query;

        if (!playerId || !matchId) {
          return reply
            .status(400)
            .send({ error: 'playerId and matchId are required' });
        }

        const stats = await getMatchStats({ playerId, matchId });

        return reply.status(200).send(stats);
      } catch (error) {
        console.error(error);
        return reply.status(500).send({ error: 'Internal Server Error' });
      }
    }
  );
};
