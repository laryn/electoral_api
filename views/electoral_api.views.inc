<?php

/*
 * @file
 * Views stuff for electoral_api.
 */

/**
 * Implements hook_views_data().
 */
function electoral_api_views_data() {
  $data['electoral_api_legislators']['table']['group'] = t('Congress');
  $data['electoral_api_legislators']['table']['base'] = array(
    'field' => 'legislator_id',
    'title' => t('Congress'),
    'help' => t("The current members of Congress as returned by the Sunlight API."),
  );
  $data['electoral_api_legislators']['firstname'] = array(
    'title' => t('First Name'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['middlename'] = array(
    'title' => t('Middle Name'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['lastname'] = array(
    'title' => t('Last Name'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['name_suffix'] = array(
    'title' => t('Name Suffix'),
    'help' => t('"Jr." for example.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['nickname'] = array(
    'title' => t('Nickname'),
    'help' => ' ',
    'field' => array(
      'handler' => 'electoral_api_handler_field_nickname',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['title'] = array(
    'title' => t('Title'),
    'help' => t('Usually "Sen" or "Rep".'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_title',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'electoral_api_handler_filter_title',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['electoral_api_legislators']['chamber'] = array(
    'real field' => 'title',
    'title' => t('Chamber'),
    'help' => t('"Senate" or "House".'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_chamber',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['party'] = array(
    'title' => t('Party'),
    'help' => ' ',
    'field' => array(
      'handler' => 'electoral_api_handler_field_party',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'electoral_api_handler_filter_party',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['electoral_api_legislators']['state'] = array(
    'title' => t('State'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'electoral_api_handler_filter_state',
      'allow empty' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['electoral_api_legislators']['district'] = array(
    'title' => t('District'),
    'help' => t('District number.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'electoral_api_handler_argument_district',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'electoral_api_handler_filter_district',
      'help' => t('Not useful unless used in combination with the state filter.'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['electoral_api_legislators']['gender'] = array(
    'title' => t('Gender'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument',
    ),
    'filter' => array(
      'handler' => 'electoral_api_handler_filter_gender',
      'allow empty' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['phone'] = array(
    'title' => t('Phone'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['fax'] = array(
    'title' => t('Fax'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['website'] = array(
    'title' => t('Website'),
    'help' => ' ',
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_website',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['webform'] = array(
    'title' => t('Webform'),
    'help' => t("URL of the congress person's web-based contact form."),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_webform',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['email'] = array(
    'title' => t('Email'),
    'help' => ' ',
    'field' => array(
      'handler' => 'electoral_api_handler_field_url',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['congress_office'] = array(
    'title' => t('Congress Office'),
    'help' => 'Office address',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['bioguide_id'] = array(
    'title' => t('BioGuide page'),
    'help' => t('http://bioguide.congress.gov/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_bioguide',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['votesmart_id'] = array(
    'title' => t('VoteSmart page'),
    'help' => t('http://votesmart.org/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_votesmart',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['fec_id'] = array(
    'title' => t('FEC ID'),
    'help' => ' ',
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['govtrack_id'] = array(
    'title' => t('Govtrack page'),
    'help' => t('http://govtrack.us/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_govtrack',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['crp_id'] = array(
    'title' => t('OpenSecrets page'),
    'help' => t('http://www.opensecrets.org/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_opensecrets',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['congresspedia_url'] = array(
    'title' => t('OpenCongress page'),
    'help' => t('http://www.opencongress.org/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_congresspedia',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['twitter_id'] = array(
    'title' => t('Twitter Page'),
    'help' => t('http://twitter.com/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_twitter',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['youtube_url'] = array(
    'title' => t('YouTube Page'),
    'help' => t('http://youtube.com/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_youtube',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['facebook_url'] = array(
    'real field' => 'facebook_id',
    'title' => t('Facebook URL'),
    'help' => t('http://www.facebook.com/'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_facebook',
      'click sortable' => TRUE,
    ),
  );
  $data['electoral_api_legislators']['picture'] = array(
    'title' => t('Picture'),
    'help' => t('Profile picture.'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_congress_picture',
    ),
  );
  $data['electoral_api_legislators']['progressive_punch'] = array(
    'title' => t('Progressive Punch Page'),
    'help' => t('http://progressivepunch.org'),
    'field' => array(
      'handler' => 'electoral_api_handler_field_url_favicon_progressive_punch',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function electoral_api_views_handlers() {
  return array(
    'info' => array(
      'path' => backdrop_get_path('module', 'electoral_api') . '/views',
    ),
    'handlers' => array(
      'electoral_api_handler_field_congress_picture' => array(
        'parent' => 'views_handler_field',
      ),
      'electoral_api_handler_field_title' => array(
        'parent' => 'views_handler_field',
      ),
      'electoral_api_handler_field_chamber' => array(
        'parent' => 'views_handler_field',
      ),
      'electoral_api_handler_field_nickname' => array(
        'parent' => 'views_handler_field',
      ),
      'electoral_api_handler_field_party' => array(
        'parent' => 'views_handler_field',
      ),
      // URLs.
      'electoral_api_handler_field_url_favicon' => array(
        'parent' => 'views_handler_field_url',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_facebook' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_youtube' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_bioguide' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_votesmart' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_govtrack' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_opensecrets' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_congresspedia' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_twitter' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_generic' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_webform' => array(
        'parent' => 'electoral_api_handler_field_url_favicon_generic',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_website' => array(
        'parent' => 'electoral_api_handler_field_url_favicon_generic',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      'electoral_api_handler_field_url_favicon_progressive_punch' => array(
        'parent' => 'electoral_api_handler_field_url_favicon',
        'file' => 'electoral_api_handler_field_url.inc',
      ),
      // Filters.
      'electoral_api_handler_filter_title' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'electoral_api_handler_filter_party' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'electoral_api_handler_filter_gender' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'electoral_api_handler_filter_state' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'electoral_api_handler_filter_district' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      // Arguments.
      'electoral_api_handler_argument_district' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
    ),
  );
}
