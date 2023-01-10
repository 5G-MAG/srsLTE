#include "srsgnb/hdr/stack/ric/e2ap.h"
#include "srsran/asn1/e2ap.h"
#include "srsran/common/test_common.h"
#include "srsran/interfaces/e2_metrics_interface.h"
#include "srsran/interfaces/enb_metrics_interface.h"
#include "srsran/srsran.h"

class dummy_metrics_interface : public srsenb::e2_interface_metrics
{
  bool pull_metrics(srsenb::enb_metrics_t* m) { return true; }
};
// function to test the encoding of the E2AP message
void test_reference_e2ap_setup_request()
{
  uint8_t e2ap_msg_foreign[] = {
      0x00, 0x01, 0x00, 0x82, 0x40, 0x00, 0x00, 0x04, 0x00, 0x31, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x09, 0x00,
      0x37, 0x34, 0x37, 0x38, 0xb5, 0xc6, 0x77, 0x88, 0x00, 0x0a, 0x00, 0x81, 0xff, 0x00, 0x00, 0x08, 0x00, 0x81, 0xf9,
      0x00, 0x00, 0x00, 0x81, 0xe9, 0x20, 0xc0, 0x4f, 0x52, 0x41, 0x4e, 0x2d, 0x45, 0x32, 0x53, 0x4d, 0x2d, 0x4b, 0x50,
      0x4d, 0x00, 0x00, 0x05, 0x4f, 0x49, 0x44, 0x31, 0x32, 0x33, 0x05, 0x00, 0x4b, 0x50, 0x4d, 0x20, 0x6d, 0x6f, 0x6e,
      0x69, 0x74, 0x6f, 0x72, 0x08, 0xdc, 0x2b, 0xda, 0xe3, 0xae, 0xd1, 0x4d, 0x00, 0x60, 0x00, 0x01, 0x01, 0x07, 0x00,
      0x50, 0x65, 0x72, 0x69, 0x6f, 0x64, 0x69, 0x63, 0x20, 0x72, 0x65, 0x70, 0x6f, 0x72, 0x74, 0x01, 0x05, 0x14, 0x01,
      0x01, 0x1d, 0x00, 0x4f, 0x2d, 0x44, 0x55, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74,
      0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20,
      0x35, 0x47, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f,
      0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x02, 0x1d, 0x00, 0x4f, 0x2d, 0x44, 0x55, 0x20,
      0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e,
      0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x45, 0x50, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e,
      0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01,
      0x01, 0x00, 0x01, 0x03, 0x1e, 0x80, 0x4f, 0x2d, 0x43, 0x55, 0x2d, 0x43, 0x50, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75,
      0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f,
      0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x35, 0x47, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64,
      0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x04, 0x1e,
      0x80, 0x4f, 0x2d, 0x43, 0x55, 0x2d, 0x43, 0x50, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e,
      0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65,
      0x20, 0x45, 0x50, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c,
      0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x05, 0x1e, 0x80, 0x4f, 0x2d, 0x43, 0x55,
      0x2d, 0x55, 0x50, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e,
      0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x35, 0x47, 0x43, 0x20,
      0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e,
      0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x06, 0x1e, 0x80, 0x4f, 0x2d, 0x43, 0x55, 0x2d, 0x55, 0x50, 0x20, 0x4d,
      0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65,
      0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x45, 0x50, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65,
      0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01,
      0x00, 0x02, 0x00, 0x00, 0x05, 0x4f, 0x49, 0x44, 0x31, 0x32, 0x33, 0x00, 0x32, 0x00, 0x22, 0x00, 0x00, 0x00, 0x33,
      0x00, 0x1c, 0x00, 0x00, 0xe0, 0x6e, 0x67, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x66, 0x00, 0x07, 0x72, 0x65, 0x71, 0x70,
      0x61, 0x72, 0x74, 0x07, 0x72, 0x65, 0x73, 0x70, 0x61, 0x72, 0x74};
  uint8_t e2ap_msg_self[] = {
      0x00, 0x01, 0x00, 0x82, 0x3c, 0x00, 0x00, 0x04, 0x00, 0x31, 0x00, 0x02, 0x00, 0x01, 0x00, 0x03, 0x00, 0x09, 0x00,
      0x37, 0x34, 0x37, 0x38, 0xb5, 0xc6, 0x77, 0x88, 0x00, 0x0a, 0x00, 0x81, 0xfa, 0x00, 0x00, 0x08, 0x00, 0x81, 0xf4,
      0x00, 0x00, 0x00, 0x81, 0xe9, 0x20, 0xc0, 0x4f, 0x52, 0x41, 0x4e, 0x2d, 0x45, 0x32, 0x53, 0x4d, 0x2d, 0x4b, 0x50,
      0x4d, 0x00, 0x00, 0x05, 0x4f, 0x49, 0x44, 0x31, 0x32, 0x33, 0x05, 0x00, 0x4b, 0x50, 0x4d, 0x20, 0x6d, 0x6f, 0x6e,
      0x69, 0x74, 0x6f, 0x72, 0x08, 0x60, 0x28, 0x38, 0x61, 0xaa, 0xe3, 0x3f, 0x00, 0x60, 0x00, 0x01, 0x01, 0x07, 0x00,
      0x50, 0x65, 0x72, 0x69, 0x6f, 0x64, 0x69, 0x63, 0x20, 0x72, 0x65, 0x70, 0x6f, 0x72, 0x74, 0x01, 0x05, 0x14, 0x01,
      0x01, 0x1d, 0x00, 0x4f, 0x2d, 0x44, 0x55, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74,
      0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20,
      0x35, 0x47, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f,
      0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x02, 0x1d, 0x00, 0x4f, 0x2d, 0x44, 0x55, 0x20,
      0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e,
      0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x45, 0x50, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e,
      0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01,
      0x01, 0x00, 0x01, 0x03, 0x1e, 0x80, 0x4f, 0x2d, 0x43, 0x55, 0x2d, 0x43, 0x50, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75,
      0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f,
      0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x35, 0x47, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64,
      0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x04, 0x1e,
      0x80, 0x4f, 0x2d, 0x43, 0x55, 0x2d, 0x43, 0x50, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e,
      0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65,
      0x20, 0x45, 0x50, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c,
      0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x05, 0x1e, 0x80, 0x4f, 0x2d, 0x43, 0x55,
      0x2d, 0x55, 0x50, 0x20, 0x4d, 0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e,
      0x74, 0x61, 0x69, 0x6e, 0x65, 0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x35, 0x47, 0x43, 0x20,
      0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e,
      0x74, 0x01, 0x01, 0x01, 0x01, 0x00, 0x01, 0x06, 0x1e, 0x80, 0x4f, 0x2d, 0x43, 0x55, 0x2d, 0x55, 0x50, 0x20, 0x4d,
      0x65, 0x61, 0x73, 0x75, 0x72, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x61, 0x69, 0x6e, 0x65,
      0x72, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x74, 0x68, 0x65, 0x20, 0x45, 0x50, 0x43, 0x20, 0x63, 0x6f, 0x6e, 0x6e, 0x65,
      0x63, 0x74, 0x65, 0x64, 0x20, 0x64, 0x65, 0x70, 0x6c, 0x6f, 0x79, 0x6d, 0x65, 0x6e, 0x74, 0x01, 0x01, 0x01, 0x01,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x23, 0x00, 0x00, 0x00, 0x33, 0x00, 0x1d, 0x00, 0x00, 0x03,
      0x80, 0x6e, 0x67, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x66, 0x00, 0x07, 0x72, 0x65, 0x71, 0x70, 0x61, 0x72, 0x74, 0x07,
      0x72, 0x65, 0x73, 0x70, 0x61, 0x72, 0x74};

  asn1::cbit_ref    bref(&e2ap_msg_foreign[0], sizeof(e2ap_msg_foreign));
  e2_ap_pdu_c       pdu;
  asn1::SRSASN_CODE unpack_ret = pdu.unpack(bref);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, unpack_ret);
  printf("Unpacked E2AP PDU %d\n", (int)unpack_ret);
  auto& ran_func_data = pdu.init_msg()
                            .value.e2setup_request()
                            ->ra_nfunctions_added.value[0]
                            .value()
                            .ra_nfunction_item()
                            .ran_function_definition;
  srsran::byte_buffer_t ran_function_def;
  asn1::cbit_ref        ran_func_bref(ran_function_def.msg, ran_function_def.get_tailroom());
  std::copy(ran_func_data.data(), ran_func_data.data() + ran_func_data.size(), ran_function_def.begin());
  e2_sm_kpm_ra_nfunction_description_s e2sm_kpm_ra_nfunction_description;
  asn1::SRSASN_CODE                    nfunc_unpack = e2sm_kpm_ra_nfunction_description.unpack(ran_func_bref);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, nfunc_unpack);
  printf("Unpacked E2SM PDU (KPM RAN function description) %d\n", (int)nfunc_unpack);
}

void test_native_e2ap_setup_request()
{
  srsran::unique_byte_buffer_t buf = srsran::make_byte_buffer();
  e2_ap_pdu_c                  pdu, pdu2;
  srslog::basic_logger&        logger = srslog::fetch_basic_logger("E2AP");
  dummy_metrics_interface      dummy_metrics;
  e2ap                         e2ap_(logger, &dummy_metrics);
  pdu = e2ap_.generate_setup_request();

  asn1::bit_ref bref(buf->msg, buf->get_tailroom());
  if (pdu.pack(bref) != asn1::SRSASN_SUCCESS) {
    printf("Failed to pack TX E2 PDU\n");
    return;
  }

  asn1::cbit_ref bref2(buf->msg, buf->get_tailroom());

  asn1::SRSASN_CODE unpack_ret = pdu2.unpack(bref2);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, unpack_ret);
  printf("Unpacked native E2AP PDU %d\n", (int)unpack_ret);
}

void test_reference_e2ap_subscription_request()
{
  uint8_t e2ap_msg_foreign[] = {0x00, 0x08, 0x40, 0x2b, 0x00, 0x00, 0x03, 0x00, 0x1d, 0x00, 0x05, 0x00,
                                0x00, 0x7b, 0x00, 0x15, 0x00, 0x05, 0x00, 0x02, 0x00, 0x01, 0x00, 0x1e,
                                0x00, 0x15, 0x00, 0x04, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x13, 0x40,
                                0x0a, 0x60, 0x01, 0x00, 0x04, 0x01, 0x02, 0x03, 0x04, 0x02, 0x00};

  asn1::cbit_ref    bref(&e2ap_msg_foreign[0], sizeof(e2ap_msg_foreign));
  e2_ap_pdu_c       pdu;
  asn1::SRSASN_CODE unpack_ret = pdu.unpack(bref);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, unpack_ret);
  printf("Unpacked E2AP PDU (subscription request) %d\n", (int)unpack_ret);
}

void test_native_e2ap_subscription_response()
{
  srsran::unique_byte_buffer_t buf = srsran::make_byte_buffer();
  e2_ap_pdu_c                  pdu, pdu2;
  srslog::basic_logger&        logger = srslog::fetch_basic_logger("E2AP");
  dummy_metrics_interface      dummy_metrics;
  e2ap                         e2ap_(logger, &dummy_metrics);
  pdu = e2ap_.generate_subscription_response();

  pdu = e2ap_.generate_subscription_response();
  asn1::bit_ref bref(buf->msg, buf->get_tailroom());
  if (pdu.pack(bref) != asn1::SRSASN_SUCCESS) {
    printf("Failed to pack TX E2 PDU\n");
    return;
  }

  asn1::cbit_ref    bref2(buf->msg, buf->get_tailroom());
  asn1::SRSASN_CODE unpack_ret = pdu2.unpack(bref2);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, unpack_ret);
  printf("Unpacked native E2AP PDU (subscription response) %d\n", (int)unpack_ret);
}

void test_native_e2ap_reset_request()
{
  srsran::unique_byte_buffer_t buf = srsran::make_byte_buffer();
  e2_ap_pdu_c                  pdu, pdu2;
  srslog::basic_logger&        logger = srslog::fetch_basic_logger("E2AP");
  dummy_metrics_interface      dummy_metrics;
  e2ap                         e2ap_(logger, &dummy_metrics);

  pdu = e2ap_.generate_reset_request();
  asn1::bit_ref bref(buf->msg, buf->get_tailroom());
  if (pdu.pack(bref) != asn1::SRSASN_SUCCESS) {
    printf("Failed to pack TX E2 PDU\n");
    return;
  }

  asn1::cbit_ref bref2(buf->msg, buf->get_tailroom());
  asn1::SRSASN_CODE unpack_ret = pdu2.unpack(bref2);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, unpack_ret);
  printf("Unpacked native E2AP PDU RESET %d\n", (int)unpack_ret);
}

void test_native_e2ap_reset_response()
{
  srsran::unique_byte_buffer_t buf = srsran::make_byte_buffer();
  e2_ap_pdu_c                  pdu, pdu2;
  srslog::basic_logger&        logger = srslog::fetch_basic_logger("E2AP");
  dummy_metrics_interface      dummy_metrics;
  e2ap                         e2ap_(logger, &dummy_metrics);

  pdu = e2ap_.generate_reset_response();
  asn1::bit_ref bref(buf->msg, buf->get_tailroom());
  if (pdu.pack(bref) != asn1::SRSASN_SUCCESS) {
    printf("Failed to pack TX E2 PDU\n");
    return;
  }

  asn1::cbit_ref    bref2(buf->msg, buf->get_tailroom());
  asn1::SRSASN_CODE unpack_ret = pdu2.unpack(bref2);
  TESTASSERT_EQ(asn1::SRSASN_SUCCESS, unpack_ret);
  printf("Unpacked native E2AP PDU RESET RESPONSE %d\n", (int)unpack_ret);
}
// add tets for set-up request and response

int main()
{
  test_reference_e2ap_setup_request();
  test_native_e2ap_setup_request();
  test_reference_e2ap_subscription_request();
  test_native_e2ap_subscription_response();
  test_native_e2ap_reset_request();
  test_native_e2ap_reset_response();
  // call reset test functions here
  return 0;
}
