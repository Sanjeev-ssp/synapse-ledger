# Blockchain — Private Ethereum Network

Smart contracts and blockchain setup for Synapse Ledger, developed and tested with **Ganache** and **Remix IDE**.

## Contracts
- `contracts/ShipmentLedger.sol` — stores immutable shipment events (location, tamper status, weight) reported by Sentinel Units.

## Local Development
1. Install [Ganache](https://trufflesuite.com/ganache/) for a local private Ethereum network.
2. Deploy `ShipmentLedger.sol` via [Remix IDE](https://remix.ethereum.org) or Truffle/Hardhat, pointed at your Ganache RPC endpoint (default `http://127.0.0.1:7545`).
3. Update the backend's `.env` with the deployed contract address and ABI path so it can write events.

## Status
🚧 Skeleton contract — extend with access control, NFC content-hash verification, and event querying as needed.
