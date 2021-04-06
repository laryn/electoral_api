<?php

/**
 * Filter handler for party.
 */
class electoral_api_civicrm_handler_filter_gender extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!civicrm_initialize()) {
      return;
    }
    require_once 'CRM/Core/PseudoConstant.php';
    $genders = CRM_Core_PseudoConstant::gender();
    foreach ($genders as $gender) {
      $this->value_options[backdrop_substr($gender, 0, 1)] = $gender;
    }
  }
}
