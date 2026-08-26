const express = require('express');
const router = express.Router();

// POST /api/sentinel-data
// Receives a signed data packet from a Sentinel Unit.
router.post('/', async (req, res) => {
  try {
    const packet = req.body;

    // TODO: 1. Verify cryptographic signature (ATECC608B public key)
    // TODO: 2. Validate packet schema (location, weight, tamper status, etc.)
    // TODO: 3. Write verified event to the blockchain (see blockchain/contracts)
    // TODO: 4. Trigger alert if tampering flag is set

    console.log('Received packet:', packet);
    res.status(200).json({ status: 'received' });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: 'Failed to process packet' });
  }
});

// GET /api/sentinel-data/:unitId
// Returns latest status + history for the dashboard.
router.get('/:unitId', async (req, res) => {
  // TODO: fetch from blockchain / database
  res.status(200).json({ unitId: req.params.unitId, status: 'not yet implemented' });
});

module.exports = router;
