<?php

/**
 * Filter handler for party.
 */
class electoral_api_handler_filter_gender extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_options = array(
        'M' => t('Male'),
        'F' => t('Female'),
        'T' => t('Transgender'),
      );
    }
  }
}
