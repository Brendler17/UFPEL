import fastify from 'fastify';
import {
  serializerCompiler,
  validatorCompiler,
  type ZodTypeProvider,
} from 'fastify-type-provider-zod';
import { getMatchStatsRoute } from './routes/get-match-stats';
import { getAllTimeStatsRoute } from './routes/get-all-time-stats';
import { getPlayerSubscriptionRoute } from './routes/get-player-subscription';
import { getGunStatsRoute } from './routes/get-gun-stats';

const app = fastify().withTypeProvider<ZodTypeProvider>();

app.setValidatorCompiler(validatorCompiler);
app.setSerializerCompiler(serializerCompiler);

app.register(getMatchStatsRoute);
app.register(getAllTimeStatsRoute);
app.register(getPlayerSubscriptionRoute);
app.register(getGunStatsRoute);

app.listen({ port: 3333 }).then(() => {
  console.log('Server is running on http://localhost:3333');
});
