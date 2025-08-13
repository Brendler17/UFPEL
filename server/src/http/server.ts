import fastify from 'fastify';
import {
  serializerCompiler,
  validatorCompiler,
  type ZodTypeProvider,
} from 'fastify-type-provider-zod';
import fastifyCors from '@fastify/cors';
import { getMatchStatsRoute } from './routes/get-match-stats';
import { getAllTimeStatsRoute } from './routes/get-all-time-stats';
import { getPlayerSubscriptionRoute } from './routes/get-player-subscription';
import { getGunStatsRoute } from './routes/get-gun-stats';
import { getMapStatsRoute } from './routes/get-map-stats';
import { getPlayersRankRoute } from './routes/get-players-rank';
import { getPlayerHistoryRoute } from './routes/get-player-history';

import { setupTriggers } from '../db/trigger';

const app = fastify().withTypeProvider<ZodTypeProvider>();

app.setValidatorCompiler(validatorCompiler);
app.setSerializerCompiler(serializerCompiler);

app.register(fastifyCors, {
  origin: '*',
});

app.register(getMatchStatsRoute);
app.register(getAllTimeStatsRoute);
app.register(getPlayerSubscriptionRoute);
app.register(getGunStatsRoute);
app.register(getMapStatsRoute);
app.register(getPlayersRankRoute);
app.register(getPlayerHistoryRoute);

async function startServer() {
  try {
    await setupTriggers();
    await app.listen({ port: 3333 });
    console.log('Server is running on http://localhost:3333');
  } catch (err) {
    console.error(err);
    process.exit(1);
  }
}

startServer();

// app.listen({ port: 3333 }).then(() => {
//   console.log('Server is running on http://localhost:3333');
// });
