import type { FastifyPluginAsyncZod } from 'fastify-type-provider-zod';
import { getPlayersRank } from '../../features/getPlayersRank';

export const getPlayersRankRoute: FastifyPluginAsyncZod = async app => {
  app.get('/players-rank', async (request, reply) => {
    try {
      const rank = await getPlayersRank();

      return reply.status(200).send(rank);
    } catch (error) {
      console.error(error);
      return reply.status(500).send({ error: 'Internal Server Error' });
    }
  });
};
