import fastify from 'fastify';
import {
  serializerCompiler,
  validatorCompiler,
  type ZodTypeProvider,
} from 'fastify-type-provider-zod';
import { getMatchStatsRoute } from './routes/get-match-stats';

const app = fastify().withTypeProvider<ZodTypeProvider>();

app.setValidatorCompiler(validatorCompiler);
app.setSerializerCompiler(serializerCompiler);

app.register(getMatchStatsRoute);

app.listen({ port: 3333 }).then(() => {
  console.log('Server is running on http://localhost:3333');
});
