// SPDX-License-Identifier: MIT
pragma solidity ^0.8.19;

/// @title ShipmentLedger
/// @notice Stores immutable, timestamped shipment events reported by Sentinel Units.
contract ShipmentLedger {
    struct ShipmentEvent {
        string unitId;
        int256 latitude;   // scaled (e.g. x1e6) to avoid floats
        int256 longitude;
        bool tampered;
        uint256 weight;    // in grams
        uint256 timestamp;
    }

    ShipmentEvent[] public events;

    event NewShipmentEvent(
        string unitId,
        bool tampered,
        uint256 timestamp
    );

    /// @notice Records a new verified event from a Sentinel Unit.
    function logEvent(
        string memory _unitId,
        int256 _latitude,
        int256 _longitude,
        bool _tampered,
        uint256 _weight
    ) public {
        events.push(ShipmentEvent(_unitId, _latitude, _longitude, _tampered, _weight, block.timestamp));
        emit NewShipmentEvent(_unitId, _tampered, block.timestamp);
    }

    function getEventCount() public view returns (uint256) {
        return events.length;
    }
}
