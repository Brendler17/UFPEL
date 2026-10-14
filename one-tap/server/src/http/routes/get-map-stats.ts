import { z } from 'zod';
import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getMapStats } from '../../features/getMapStats';

export const getMapStatsRoute: FastifyPluginAsyncZod = async app => {
  app.get(
    '/map-stats',
    {
      schema: {
        querystring: z.object({
          playerId: z.string(),
          //mapId: z.string(),
        }),
      },
    },
    async (request, reply) => {
      try {
        const { playerId /*, mapId */ } = request.query;

        if (!playerId /*|| !mapId*/) {
          return reply
            .status(400)
            .send({ error: 'playerId and mapId are required' });
        }

        const stats = await getMapStats({ playerId /*, mapId */ });

        return reply.status(200).send(stats);
      } catch (error) {
        console.error(error);
        return reply.status(500).send({ error: 'Internal Server Error' });
      }
    }
  );
};
