import { z } from 'zod';
import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getGunStats } from '../../features/getGunStats';

export const getGunStatsRoute: FastifyPluginAsyncZod = async app => {
  app.get(
    '/gun-stats',
    {
      schema: {
        querystring: z.object({
          playerId: z.string(),
          //gunId: z.string(),
        }),
      },
    },
    async (request, reply) => {
      try {
        const { playerId /*gunId*/ } = request.query;

        if (!playerId /*|| !gunId*/) {
          return reply
            .status(400)
            .send({ error: 'playerId and gunId are required' });
        }

        const stats = await getGunStats({ playerId /*, gunId*/ });

        return reply.status(200).send(stats);
      } catch (error) {
        console.error(error);
        return reply.status(500).send({ error: 'Internal Server Error' });
      }
    }
  );
};
