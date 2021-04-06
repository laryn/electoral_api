<?php

/*
 * @file
 * Views stuff for electoral_api_civicrm.
 */

/**
 * Implements hook_views_data_alter().
 */
function electoral_api_civicrm_views_data_alter(&$data) {
  $data['electoral_api_legislators']['state_current'] = array(
    'real field' => 'state',
    'title' => t("Current User's State"),
    'help' => t('Filter the view to the State of the currently logged in user.'),
    'filter' => array(
      'handler' => 'electoral_api_civicrm_handler_filter_state_current_user',
      'type' => 'yes-no',
    ),
  );
  $data['electoral_api_legislators']['district_current'] = array(
    'real field' => 'district',
    'title' => t("Current User's District"),
    'help' => t('Filter the view to the District of the currently logged in user.
              Only useful when used with the %current_state filter.',
              array('%current_state' => t("Current User's State"))),
    'filter' => array(
      'handler' => 'electoral_api_civicrm_handler_filter_district_current_user',
      'type' => NULL,
    ),
  );
  $data['electoral_api_legislators']['state']['filter']['handler'] = 'electoral_api_civicrm_handler_filter_state';
  $data['electoral_api_legislators']['gender']['filter']['handler'] = 'electoral_api_civicrm_handler_filter_gender';
}

/**
 * Implements hook_views_default_views_alter().
 */
function electoral_api_civicrm_views_default_views_alter(&$views) {
  if (isset($views['congress'])) {
    $view = & $views['congress'];
    /* Display: Block - Current user */
    $handler = $view->new_display('block', 'Block - Current user', 'block_3');
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter: Congress: Current User's District */
    $handler->display->display_options['filters']['district_current']['id'] = 'district_current';
    $handler->display->display_options['filters']['district_current']['table'] = 'electoral_api_legislators';
    $handler->display->display_options['filters']['district_current']['field'] = 'district_current';
    $handler->display->display_options['filters']['district_current']['value'] = '1';
    $handler->display->display_options['filters']['district_current']['expose']['operator'] = FALSE;
    /* Filter: Congress: Current User's State */
    $handler->display->display_options['filters']['state_current']['id'] = 'state_current';
    $handler->display->display_options['filters']['state_current']['table'] = 'electoral_api_legislators';
    $handler->display->display_options['filters']['state_current']['field'] = 'state_current';
    $handler->display->display_options['filters']['state_current']['value'] = '1';
    $handler->display->display_options['filters']['state_current']['expose']['operator'] = FALSE;

    /* Display: Page - Current user */
    $handler = $view->new_display('page', 'Page - Current user', 'page_2');
    $handler->display->display_options['defaults']['filters'] = FALSE;
    /* Filter: Congress: Current User's District */
    $handler->display->display_options['filters']['district_current']['id'] = 'district_current';
    $handler->display->display_options['filters']['district_current']['table'] = 'electoral_api_legislators';
    $handler->display->display_options['filters']['district_current']['field'] = 'district_current';
    $handler->display->display_options['filters']['district_current']['expose']['operator'] = FALSE;
    /* Filter: Congress: Current User's State */
    $handler->display->display_options['filters']['state_current']['id'] = 'state_current';
    $handler->display->display_options['filters']['state_current']['table'] = 'electoral_api_legislators';
    $handler->display->display_options['filters']['state_current']['field'] = 'state_current';
    $handler->display->display_options['filters']['state_current']['value'] = '1';
    $handler->display->display_options['filters']['state_current']['expose']['operator'] = FALSE;
    $handler->display->display_options['path'] = 'my-congress';
  }
}

/**
 * Implements hook_views_handlers().
 */
function electoral_api_civicrm_views_handlers() {
  return array(
    'info' => array(
      'path' => backdrop_get_path('module', 'electoral_api_civicrm') . '/views',
    ),
    'handlers' => array(
      'electoral_api_civicrm_handler_filter_state_current_user' => array(
        'parent' => 'views_handler_filter_boolean_operator',
        'file' => 'electoral_api_civicrm_handler_filter_current_user.inc',
      ),
      'electoral_api_civicrm_handler_filter_district_current_user' => array(
        'parent' => 'views_handler_filter_boolean_operator',
        'file' => 'electoral_api_civicrm_handler_filter_current_user.inc',
      ),
      'electoral_api_civicrm_handler_filter_state' => array(
        'parent' => 'electoral_api_handler_filter_state',
      ),
      'electoral_api_civicrm_handler_filter_gender' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_query_substitutions().
 */
function electoral_api_views_query_substitutions($view) {
  global $user;
  $substitutions = array();
  if ($view->base_table == 'electoral_api_legislators') {
    $substitutions['***CURRENT_USERS_STATE***'] = 'NULL';
    $substitutions['***CURRENT_USERS_DISTRICT***'] = 'NULL';
    if ($user->uid) {
      $cd = electoral_api_civicrm_user_get_cd($user->uid);
      if ($cd && $cd != 'not found') {
        $substitutions['***CURRENT_USERS_STATE***'] = electoral_api_cd_parse_state($cd);
        $substitutions['***CURRENT_USERS_DISTRICT***'] = intval(electoral_api_cd_parse_district($cd));
      }
    }
  }
  return $substitutions;
}
