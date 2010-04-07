<?php
// $Id$

/**
 * Implementation of hook_views_default_views().
 */
function enabled_modules_views_default_views() {
  /*
   * View 'enabled_modules_list'
   */
  $view = new view;
  $view->name = 'enabled_modules_list';
  $view->description = 'A view designed for anybody to see, listing the enabled modules in this Drupal installation.';
  $view->tag = 'enabled_modules';
  $view->view_php = '';
  $view->base_table = 'system';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'project' => array(
      'label' => 'Project',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'http://drupal.org/project/[project]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'project',
      'table' => 'enabled_modules_system',
      'field' => 'project',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'name',
      'table' => 'system',
      'field' => 'name',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'name_1' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 1,
        'text' => '[name_1] ([name])',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'name_1',
      'table' => 'enabled_modules_system',
      'field' => 'name',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'project' => array(
      'order' => 'ASC',
      'id' => 'project',
      'table' => 'enabled_modules_system',
      'field' => 'project',
      'relationship' => 'none',
    ),
    'name' => array(
      'order' => 'ASC',
      'id' => 'name',
      'table' => 'enabled_modules_system',
      'field' => 'name',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => '=',
      'value' => 'module',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'type',
      'table' => 'system',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'system',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'package' => array(
      'operator' => '!=',
      'value' => 'Core - required',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'package',
      'table' => 'enabled_modules_system',
      'field' => 'package',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view enabled modules',
  ));
  $handler->override_option('cache', array(
    'type' => 'time',
    'results_lifespan' => '21600',
    'output_lifespan' => '21600',
  ));
  $handler->override_option('title', 'Enabled Modules');
  $handler->override_option('header', '<strong>This page shows the Drupal modules that have been used to build this site.</strong>

  Click on the project name to visit the project page on Drupal.org.');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'grid');
  $handler->override_option('style_options', array(
    'grouping' => 'project',
    'columns' => '4',
    'alignment' => 'horizontal',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'enabled_modules');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Enabled Modules',
    'description' => 'A list of the Drupal modules enabled on this website',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));
  $views[$view->name] = $view;

  return $views;
}



