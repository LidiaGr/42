<?php
 /**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', '123' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '(|ig_/U$mzNXYAdN~Se.~_^dVvz!iF@YrE~=kK,C8<xi)n`]R4 4MaCIA$(V<DD]');
define('SECURE_AUTH_KEY',  'NTWf0Q}} 7L:C3V.d2d+sIi ssNqB??U@8hDlr+};}RhYCF|KF_PW9bi`L7SJlR0');
define('LOGGED_IN_KEY',    'UPe[d)SUDc|O<9xoKDct1dh5U@,[jgs{nFQ5|$oy[[Y$T[2lj~>YNnj+>!ZS}x!<');
define('NONCE_KEY',        's-v_t;+fEf&q=+v)^C6IYC+Pegy}o;#xg;QqL_)WUfCzM]6Gq+(|+Ew)vhyu8P7]');
define('AUTH_SALT',        '5Wjr/eRl}}mZP%-?BHT4Vp!,dy)4uO$,g-u/]BU~n6N*q0}a}+|ljPVE>XLPU,qE');
define('SECURE_AUTH_SALT', 'sl?)j2;{)||+3xCD&~,el]85a^JhoIuEg4Miaun::/+&8{>4e<+]Lo-WKp|I6WGJ');
define('LOGGED_IN_SALT',   '|DWN/Q1Q^`Sr+i-trVfHDX-L7d~5]?NOBJU+=Y_<:_8Gt!RE=Wt2R+W;lUB,tmji');
define('NONCE_SALT',       '.(*o|[Hu=WBlwary:I{YiWqlG*l].}PIWLHB8C09zLlNb1Y@[Nc#U9p F|WFF%y+');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );