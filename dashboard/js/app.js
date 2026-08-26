// Synapse Ledger Dashboard — front-end logic
// Fetches live and historical data from the backend API and renders it.

const API_BASE = 'http://localhost:4000/api/sentinel-data';

async function fetchUnitStatus(unitId) {
  try {
    const res = await fetch(`${API_BASE}/${unitId}`);
    const data = await res.json();
    console.log('Unit status:', data);
    // TODO: render onto map + status panel
  } catch (err) {
    console.error('Failed to fetch unit status:', err);
  }
}

document.addEventListener('DOMContentLoaded', () => {
  console.log('Synapse Ledger dashboard loaded.');
  // fetchUnitStatus('UNIT-01');
});
