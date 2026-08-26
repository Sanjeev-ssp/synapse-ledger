/*
  Synapse Ledger — Backend Server
  Receives signed data packets from Sentinel Units, validates them,
  writes verified events to the blockchain, and serves the dashboard API.
*/

const express = require('express');
const cors = require('cors');
require('dotenv').config();

const sentinelRoutes = require('./routes/sentinel');

const app = express();
const PORT = process.env.PORT || 4000;

app.use(cors());
app.use(express.json());

app.get('/', (req, res) => {
  res.send('Synapse Ledger backend is running.');
});

app.use('/api/sentinel-data', sentinelRoutes);

app.listen(PORT, () => {
  console.log(`Synapse Ledger backend listening on port ${PORT}`);
});
