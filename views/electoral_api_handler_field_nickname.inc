<?php

/**
 * Field handler to enclose the Nickname in quotes.
 *
 * @ingroup views_field_handlers
 */
class electoral_api_handler_field_nickname extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['quotes'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['quotes'] = array(
      '#title' => t('Enclose the nickname in quotes'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['quotes']),
    );
  }

  function render($values) {
    if (!empty($this->options['quotes']) && !empty($values->electoral_api_legislators_nickname)) {
      return '"' . $values->electoral_api_legislators_nickname . '"';
    }
    return $values->electoral_api_legislators_nickname;
  }

}
