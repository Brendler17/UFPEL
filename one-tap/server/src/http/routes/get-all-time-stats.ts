import { z } from 'zod';
import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getAllTimeStats } from '../../features/getAllTimeStats';

export const getAllTimeStatsRoute: FastifyPluginAsyncZod = async app => {
  app.get(
    '/all-time-stats',
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
          return reply.status(400).send({ error: 'playerId is required' });
        }

        const stats = await getAllTimeStats({ playerId });

        return reply.status(200).send(stats);
      } catch (error) {
        console.log(error);
        return reply.status(500).send({ error: 'internal server error' });
      }
    }
  );
};
