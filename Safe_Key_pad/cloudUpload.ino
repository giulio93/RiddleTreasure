void send_data_to_cloud() {


#ifdef BLE_SYNC
  bleOpen.setValue(bleOpen.getValue() + 1);
  ble.sync(3000);
#endif
}